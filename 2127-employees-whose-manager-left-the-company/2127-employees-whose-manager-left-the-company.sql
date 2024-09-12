# Write your MySQL query statement below
select employee_id from employees
where salary <30000
and manager_id NOT IN(SELECT EMPLOYEE_ID FROM EMPLOYEES)
ORDER BY EMPLOYEE_ID
