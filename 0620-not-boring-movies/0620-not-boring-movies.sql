# Write your MySQL query statement below
select id,movie ,description,rating 
from cinema 
where mod(id,2)=1 
and description !='Boring'
order by rating desc ;