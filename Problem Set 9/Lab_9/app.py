import os

from flask import Flask, flash, jsonify, redirect, render_template, request
from sqlalchemy import create_engine

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure SQLAlchemy Library to use SQLite database
engine = create_engine("sqlite:///birthdays.db", echo=True)


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # Add the user's entry into the database
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")
        if name or month or day:
            engine.execute("INSERT INTO birthdays (name, month, day) VALUES(:name, :month, :day)", name=name, month=month, day=day)
            return redirect("/")

        # Delete the user's entry from the database
        id = request.form.get("id")
        if id:
            engine.execute("DELETE FROM birthdays WHERE id = :id", id=id)
            return redirect("/")

        # If there's no the user's entry
        else:
            return redirect("/")

    else:

        # Display the entries in the database on index.html
        birthdays = engine.execute("SELECT * FROM birthdays")
        return render_template("index.html", birthdays=birthdays)
