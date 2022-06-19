# Write your MySQL query statement below
select c.name Customers
from customers c
where c.id NOT IN (select customerId from Orders)