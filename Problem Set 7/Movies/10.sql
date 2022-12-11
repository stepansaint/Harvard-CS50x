SELECT DISTINCT(name)
  FROM people AS p
  JOIN directors AS d
    ON p.id = d.person_id
 WHERE movie_id IN
       (SELECT id
          FROM movies AS m
          JOIN ratings AS r
            ON r.rating >= 9
           AND m.id = r.movie_id); 
