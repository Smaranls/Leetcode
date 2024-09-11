# Write your MySQL query statement below
select f.name 
from employee f
join employee s
on f.id = s.managerId
group by f.id
having count(s.managerId)>=5;