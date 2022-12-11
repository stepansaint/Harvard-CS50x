SELECT name 
  FROM people
 WHERE id IN
       (SELECT person_id 
          FROM stars AS s
          JOIN movies AS m
            ON m.year = '2004'
           AND m.id = s.movie_id)
         ORDER BY birth;