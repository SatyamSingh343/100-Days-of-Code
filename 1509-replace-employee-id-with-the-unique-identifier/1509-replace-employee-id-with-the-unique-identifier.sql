# Write your MySQL query statement below
SELECT e.name,euni.unique_id
FROM Employees AS e
LEFT JOIN  EmployeeUNI AS euni
on e.id=euni.id;