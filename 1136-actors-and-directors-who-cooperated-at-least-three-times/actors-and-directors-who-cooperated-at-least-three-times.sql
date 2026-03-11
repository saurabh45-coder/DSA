# Write your MySQL query statement below
SELECT actor_id,director_id
FROM ActorDirector
Group BY  actor_id,director_id
Having Count(*)>=3;