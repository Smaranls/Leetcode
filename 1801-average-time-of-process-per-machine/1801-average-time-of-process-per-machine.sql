select s.machine_id , round(avg(e.timestamp - s.timestamp),3) as processing_time
from activity s
join activity e
on s.machine_id= e.machine_id 
and s.process_id = e.process_id
and s.timestamp<e.timestamp
group by s.machine_id

