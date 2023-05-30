-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Getting basic description of the theft
SELECT id, description FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = 'Humphrey Street';
-- Crime took place at the bakery at 10:15AM
-- Three witnesses were interviewed

-- Get interview text for witnesses
SELECT id, transcript FROM interviews
WHERE transcript LIKE "%bakery%";
-- Within ten mins of theft thief left in a car. Looks for cars that left in that time frame.
-- Thief withdrew money from ATM of Leggett Street earlier that morning
-- Thief had a phone call of less than one min as he was leaving the bakery

-- Theif withdrew money earlier that morning from ATM of Leggett Street
-- Thief had a phone call of less than one min after 10:15 and before he drove away
-- Thief drove away in a car ten mins after the robbery
-- Thiefs name would also appear on a flight manifest

-- Names of those who exited bakery within ten mins of theft
SELECT bakery_security_logs.activity, bakery_security_logs.license_plate, people.name
FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE bakery_security_logs.year = 2021
AND bakery_security_logs.month = 7
AND bakery_security_logs.day = 28
AND bakery_security_logs.hour = 10
AND bakery_security_logs.minute >= 15
AND bakery_security_logs.minute <= 25 ORDER BY people.name;

-- atm transactions for Leggett Street that morning
SELECT people.name, atm_transactions.transaction_type FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE atm_transactions.year = 2021
AND atm_transactions.month = 7
AND atm_transactions.day = 28
AND atm_location = "Leggett Street"
AND atm_transactions.transaction_type = "withdraw" ORDER BY people.name;

-- Check into phone call
SELECT caller, receiver FROM phone_calls
WHERE year = 2021
AND month = 7
AND day = 28
AND duration < 60;

--Alter phone_calls table to include names with phone numbers
-- Update values of altered tables
UPDATE phone_calls
SET caller_name = people.name
FROM people
WHERE phone_calls.caller = people.phone_number;

UPDATE phone_calls
SET receiver_name = people.name
FROM people
WHERE phone_calls.receiver = people.phone_number;

-- Re-run phone call query to get names
SELECT caller, caller_name, receiver, receiver_name FROM phone_calls
WHERE year = 2021
AND month = 7
AND day = 28
AND duration < 60;

-- Query for earliest flight for the following day
SELECT id, hour, minute, origin_airport_id, destination_airport_id
FROM flights
WHERE year = 2021
AND month = 7
AND day = 29
ORDER BY hour ASC
LIMIT 1;
-- earliest flight id 36 is for NEW YORK CITY

-- query for passengars going on flight 36
SELECT flights.destination_airport_id, name, phone_number, license_plate FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON flights.id = passengers.flight_id
WHERE flights.id = 36
ORDER BY flights.hour ASC;