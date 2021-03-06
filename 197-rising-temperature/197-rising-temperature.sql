# Write your MySQL query statement below

# select w.id 
# from weather w join weather w1
# on datediff(w.recordDate,w1.recordDate)=1
# and w.temperature>w1.temperature;

#inner join->only those records will be joined for which join cond true

SELECT Weather.Id 
FROM   Weather 
       JOIN Weather AS w 
         ON w.RecordDate = SUBDATE(Weather.RecordDate, 1) 
WHERE  Weather.Temperature > w.Temperature 