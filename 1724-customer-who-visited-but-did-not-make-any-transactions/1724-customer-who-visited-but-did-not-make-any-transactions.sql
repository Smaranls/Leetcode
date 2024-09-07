# Write your MySQL query statement below
SELECT V.CUSTOMER_ID,COUNT(*) as count_no_trans 
FROM VISITS V
left join TRANSACTIONS T
ON V.VISIT_ID = T.VISIT_ID
WHERE T.VISIT_ID IS NULL
GROUP BY V.CUSTOMER_ID