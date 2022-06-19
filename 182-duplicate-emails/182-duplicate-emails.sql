# Write your MySQL query statement below

select p.email Email
from Person p
group by p.email
having count(*)>1;