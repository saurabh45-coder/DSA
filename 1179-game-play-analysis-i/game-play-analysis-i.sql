# Write your MySQL query statement below
SELECT player_id , MIn(event_date) AS first_login
FROM Activity
group by player_id;