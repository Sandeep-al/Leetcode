# Write your MySQL query statement below
select e.machine_id,round(avg(e.timestamp-s.timestamp),3) as processing_time
from Activity as s join Activity as e
ON s.machine_id=e.machine_id and s.process_id=e.process_id and (s.activity_type='start' and e.activity_type='end') 
group by e.machine_id;
