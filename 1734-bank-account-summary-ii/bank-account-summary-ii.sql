# Write your MySQL query statement below
SELECT NAME,sum(amount) as BALANCE
FROM Users as u
LEFT JOIN Transactions as t
ON u.account = t.account
GROUP BY NAME
HAVING  sum(amount) > 10000;