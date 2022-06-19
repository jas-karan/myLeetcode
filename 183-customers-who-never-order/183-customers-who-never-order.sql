# Write your MySQL query statement below
# select c.name Customers
# from customers c
# where c.id NOT IN (select customerId from Orders)

select c.name customers
from customers c left join orders o
on c.id = o.customerId
where o.customerId is null