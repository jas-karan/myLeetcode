# Write your MySQL query statement below
select c.name
from customer c
where c.referee_id not in (2,2) or c.referee_id IS NULL;