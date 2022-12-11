SELECT name
  FROM people
 WHERE id IN
       (SELECT person_id
          FROM stars AS s
          JOIN movies AS m
            ON m.title = 'Toy Story'
           AND m.id = s.movie_id);
