SELECT DISTINCT
    visited_on,
    amount,
    ROUND(amount / 7, 2) AS average_amount
FROM
    (
        SELECT
            visited_on,
            SUM(amount) OVER (
                ORDER BY
                    visited_on RANGE interval 6 DAY PRECEDING
            ) AS amount
        FROM
            Customer
    ) AS temp
WHERE
    DATEDIFF (
        visited_on,
        (
            SELECT
                MIN(visited_on)
            FROM
                Customer
        )
    ) >= 6