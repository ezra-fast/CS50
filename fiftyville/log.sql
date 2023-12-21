-- Keep a log of any SQL queries you execute as you solve the mystery.
select * from crime_scene_reports where year = 2021 and month = 7 and day = 28;

select caller, receiver from phone_calls where year = 2021 and day = 28 and month = 7 and duration < 60;

select license_plate from bakery_security_logs where hour = 10 and minute < 25 and minute > 15 and year = 2021 and day = 28 and month = 7;

select account_number from atm_transactions where atm_location = 'Leggett Street' and year = 2021 and month = 7 and day = 28;

select name from people where license_plate in (select license_plate from bakery_security_logs where hour = 10 and minute < 25 and minute > 15 and year = 2021 and day = 28 and month = 7) and phone_number in (select caller from phone_calls where year = 2021 and day = 28 and month = 7 and duration < 60);

select account_number from people join bank_accounts on people.id = bank_accounts.person_id where name in (select name from people where license_plate in (select license_plate from bakery_security_logs where hour = 10 and minute < 25 and minute > 15 and year = 2021 and day = 28 and month = 7) and phone_number in (select caller from phone_calls where year = 2021 and day = 28 and month = 7 and duration < 60));

select * from people join bank_accounts on people.id = bank_accounts.person_id where account_number = '49610011' or account_number = '26013199';
--This gives the earliest flight of the day after the crime, which a witness said the thief booked a ticket on:
select * from flights where day = 29 and year = 2021 and month = 7 order by hour asc limit 1;
--This gives us LaGuardia Airport, in New York City:
select * from airports where airport_destination_id = 4;
--This gives us a list of passengers from the first flight of the day:
select * from passengers where flight_id = 36;
--This narrows it down to one name (the thief): Bruce:
select name from people join bank_accounts on people.id = bank_accounts.person_id where passport_number in (select passport_number from passengers where flight_id = 36) and (account_number = '49610011' or account_number = '26013199');
--This gives us the accomplice, who was the person on the other end of this call with Bruce:
select * from phone_calls where caller = '(367) 555-5533' and year = 2021 and month = 7 and day = 28 and duration < 60;
--This gives us the accomplice, Robin:
select * from people where phone_number = '(375) 555-8161';
