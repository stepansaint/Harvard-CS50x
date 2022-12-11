SELECT COUNT(title)
  FROM movies AS m
  JOIN ratings AS r
    ON r.rating = 10
   AND r.movie_id = m.id;