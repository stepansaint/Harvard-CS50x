-- Find description of the crime
SELECT *
  FROM crime_scene_reports
 WHERE day = '28'
   AND month = '7'
   AND year = '2021'
   AND street = 'Humphrey Street';
/*
  THE CLUES:
Time: 10:15 am
Place: Humphrey Street bakery
*/


-- Look at the interviews from this day
SELECT *
  FROM interviews
 WHERE day = '28'
   AND month = '7'
   AND year = '2021';
/*
  THE EVIDENCES:
A: The thief got into a car
B: Earlier this morning the thief withdrew some money in
   the ATM on Leggett Street
C: There was a phone call (less than a minute). The thief was
   planning to take the earliest flight out of Fiftyville
   tomorrow. The thief asked the person on the other end of
   the phone to purchase the flight ticket
*/


-- Look at the logs of the bakery this day
SELECT license_plate
  FROM bakery_security_logs
 WHERE day = '28'
   AND hour BETWEEN 10 and 11
   AND activity = 'exit';
/*
  THE SUSPECT'S PLATE:
+---------------+
| license_plate |
+---------------+
| 5P2BI95       |
| 94KL13X       |
| 6P58WS2       |
| 4328GD8       |
| G412CB7       |
| L93JTIZ       |
| 322W7JE       |
| 0NTHK55       |
| 1106N58       |
+---------------+
*/


-- Look at the transactions this day in the ATM
SELECT account_number
  FROM atm_transactions
 WHERE atm_location = 'Leggett Street'
   AND transaction_type = 'withdraw'
   AND day = '28';
/*
  THE SUSPECT'S BANK ACCOUNT NUMBER:
+----------------+
| account_number |
+----------------+
| 28500762       |
| 28296815       |
| 76054385       |
| 49610011       |
| 16153065       |
| 25506511       |
| 81061156       |
| 26013199       |
+----------------+
*/


-- Check the phone calls this day
SELECT caller
  FROM phone_calls
 WHERE day = '28'
   AND duration < 60;
/*
  THE SUSPECT'S PHONE NUMBER:
+----------------+
|     caller     |
+----------------+
| (130) 555-0289 |
| (499) 555-9472 |
| (367) 555-5533 |
| (499) 555-9472 |
| (286) 555-6063 |
| (770) 555-1861 |
| (031) 555-6622 |
| (826) 555-1652 |
| (338) 555-6650 |
+----------------+
*/


-- Check the flights next day
SELECT id, origin_airport_id, destination_airport_id
  FROM flights
 WHERE day = '29'
   AND origin_airport_id IN
       (SELECT id
          FROM airports
         WHERE city = 'Fiftyville');
/*
  THE SUSPECT'S POSSIBLE FLIGHT:
+----+-------------------+------------------------+
| id | origin_airport_id | destination_airport_id |
+----+-------------------+------------------------+
| 18 | 8                 | 6                      |
| 23 | 8                 | 11                     |
| 36 | 8                 | 4                      |
| 43 | 8                 | 1                      |
| 53 | 8                 | 9                      |
+----+-------------------+------------------------+
*/


-- Check the passengers from 4 flights (above)
SELECT passport_number
  FROM passengers AS p
  JOIN flights AS f
    ON p.flight_id = f.id
 WHERE f.day = '29'
   AND f.origin_airport_id IN
       (SELECT id
          FROM airports
         WHERE city = 'Fiftyville');
/*
  THE SUSPECT'S PASSPORT NUMBER:
+-----------------+
| passport_number |
+-----------------+
| 2835165196      |
| 6131360461      |
| 3231999695      |
| 3592750733      |
| 2626335085      |
| 6117294637      |
| 2996517496      |
| 3915621712      |
| 4149859587      |
| 9183348466      |
| 7378796210      |
| 7874488539      |
| 4195341387      |
| 6263461050      |
| 3231999695      |
| 7951366683      |
| 7214083635      |
| 1695452385      |
| 5773159633      |
| 1540955065      |
| 8294398571      |
| 1988161715      |
| 9878712108      |
| 8496433585      |
| 7597790505      |
| 6128131458      |
| 6264773605      |
| 3642612721      |
| 4356447308      |
| 7441135547      |
| 7894166154      |
| 6034823042      |
| 4408372428      |
| 2312901747      |
| 1151340634      |
| 8174538026      |
| 1050247273      |
| 7834357192      |
+-----------------+
*/


-- Find the suspect by all factors (above)
SELECT *
  FROM people
 WHERE license_plate IN
       (SELECT license_plate
          FROM bakery_security_logs
         WHERE day = '28'
           AND hour BETWEEN 10 and 11
           AND activity = 'exit')

   AND phone_number IN
       (SELECT caller
          FROM phone_calls
         WHERE day = '28'
           AND duration < 60)

   AND passport_number IN
       (SELECT passport_number
          FROM passengers AS p
          JOIN flights AS f
            ON p.flight_id = f.id
         WHERE f.day = '29'
           AND f.origin_airport_id IN
               (SELECT id
                  FROM airports
                 WHERE city = 'Fiftyville'))

   AND id IN
       (SELECT person_id
          FROM bank_accounts
         WHERE account_number IN
               (SELECT account_number
                  FROM atm_transactions
                 WHERE atm_location = 'Leggett Street'
                   AND transaction_type = 'withdraw'
                   AND day = '28'));
/*
  THE SUSPECT'S INFORMATION:
+--------+--------+----------------+-----------------+---------------+
|   id   |  name  |  phone_number  | passport_number | license_plate |
+--------+--------+----------------+-----------------+---------------+
| 449774 | Taylor | (286) 555-6063 | 1988161715      | 1106N58       |
| 514354 | Diana  | (770) 555-1861 | 3592750733      | 322W7JE       |
| 686048 | Bruce  | (367) 555-5533 | 5773159633      | 94KL13X       |
+--------+--------+----------------+-----------------+---------------+
*/


-- Find the closest in time exit from the bakery based on previously information
SELECT b.*
  FROM bakery_security_logs AS b
  JOIN people AS p
    ON b.license_plate = p.license_plate
 WHERE b.activity = 'exit'
   AND p.license_plate IN
       (SELECT license_plate
          FROM bakery_security_logs
         WHERE day = '28'
           AND hour BETWEEN 10 and 11
           AND activity = 'exit')

   AND p.phone_number IN
       (SELECT caller
          FROM phone_calls
         WHERE day = '28'
           AND duration < 60)

   AND p.passport_number IN
       (SELECT passport_number
          FROM passengers AS p
          JOIN flights AS f
            ON p.flight_id = f.id
         WHERE f.day = '29'
           AND f.origin_airport_id IN
               (SELECT id
                  FROM airports
                 WHERE city = 'Fiftyville'))

   AND p.id IN
       (SELECT person_id
          FROM bank_accounts
         WHERE account_number IN
               (SELECT account_number
                  FROM atm_transactions
                 WHERE atm_location = 'Leggett Street'
                   AND transaction_type = 'withdraw'
                   AND day = '28'));
/*
  THE SUSPECT HAS THE LICENSE PLATE `94KL13X`
+-----+------+-------+-----+------+--------+----------+---------------+
| id  | year | month | day | hour | minute | activity | license_plate |
+-----+------+-------+-----+------+--------+----------+---------------+
| 268 | 2021 | 7     | 28  | 10   | 35     | exit     | 1106N58       |
| 266 | 2021 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
| 261 | 2021 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
+-----+------+-------+-----+------+--------+----------+---------------+
  THE THIEF IS `BRUCE`:
+--------+-------+----------------+-----------------+---------------+
|   id   | name  |  phone_number  | passport_number | license_plate |
+--------+-------+----------------+-----------------+---------------+
| 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       |
+--------+-------+----------------+-----------------+---------------+
*/


-- Find the city Bruce escaped to
SELECT city
  FROM airports AS a
  JOIN flights AS f
    ON a.id = f.destination_airport_id
 WHERE f.id IN
       (SELECT flight_id
          FROM passengers
         WHERE passport_number = '5773159633');
/*
  BRUCE ESCAPED TO:
+---------------+
|     city      |
+---------------+
| New York City |
+---------------+
*/


-- Find out who the accomplice is
SELECT receiver
  FROM phone_calls
 WHERE caller = '(367) 555-5533' -- Bruce's phone number
  AND day = '28'
  AND duration < 60;
/*
  THE ACCOMPLICE'S PHONE IS:
+----------------+
|    receiver    |
+----------------+
| (375) 555-8161 |
+----------------+
*/

SELECT name
  FROM people
 WHERE phone_number = '(375) 555-8161'; -- accomplice's phone number
/*
  THE ACCOMPLICE'S NAME:
+-------+
| name  |
+-------+
| Robin |
+-------+
*/