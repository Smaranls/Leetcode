# Write your MySQL query statement below
select f.employee_id,f.name as name ,  COUNT(s.employee_id) as reports_count , round(avg(s.age)) as average_age
from employees f 
join employees s
on f.employee_id = s.reports_to
group by f.employee_id
order by f.employee_id