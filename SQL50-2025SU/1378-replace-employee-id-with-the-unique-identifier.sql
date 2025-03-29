SELECT
    EmployeeUNI.unique_id,
    Employees.name
FROM
    EmployeeUNI
    RIGHT OUTER JOIN Employees ON Employees.id = EmployeeUNI.id;