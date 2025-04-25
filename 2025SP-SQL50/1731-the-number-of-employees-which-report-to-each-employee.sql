SELECT
    Mngr.employee_id,
    Mngr.name,
    COUNT(Empl.employee_id) AS reports_count,
    ROUND(AVG(Empl.age)) AS average_age
FROM
    Employees AS Mngr
    JOIN Employees AS Empl ON Mngr.employee_id = Empl.reports_to
GROUP BY
    Mngr.employee_id
ORDER BY
    Mngr.employee_id