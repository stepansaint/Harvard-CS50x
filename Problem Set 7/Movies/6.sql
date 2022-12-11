SELECT AVG(rating) AS average_rating
  FROM ratings AS r
  JOIN movies AS m
    ON m.year = '2012'
   AND m.id = r.movie_id;