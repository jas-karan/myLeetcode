# Write your MySQL query statement below

# select p.email Email
# from Person p
# group by p.email
# having count(*)>1;

select distinct p1.email Email
from person p1 join person p2
where p1.id != p2.id and p1.email = p2.email;