SELECT
    m.name
FROM
    Employee AS m
    JOIN Employee AS e ON m.id = e.managerID
GROUP BY
    m.id
HAVING
    COUNT(e.id) >= 5