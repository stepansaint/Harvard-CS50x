SELECT title
  FROM movies AS m
  JOIN ratings AS r
    ON m.id = r.movie_id
   AND m.id IN
       (SELECT movie_id
          FROM stars AS s 
          JOIN people AS p 
            ON s.person_id = p.id
           AND p.name = 'Chadwick Boseman')
         ORDER BY r.rating DESC
         LIMIT 5;