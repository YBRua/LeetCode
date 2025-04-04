SELECT
    a.visited_on,
    SUM(b.amount) AS amount,
    ROUND(SUM(b.amount) / 7, 2) AS average_amount
FROM
    (
        SELECT DISTINCT
            visited_on
        FROM
            Customer
    ) a
    JOIN Customer b ON DATEDIFF (a.visited_on, b.visited_on) BETWEEN 0 AND 6
WHERE
    a.visited_on >= (
        SELECT
            min(visited_on)
        FROM
            Customer
    ) + 6
GROUP BY
    a.visited_on
ORDER BY
    a.visited_on