SELECT
    (
        CASE
            WHEN MOD(id, 2) != 0
            AND counts != id THEN id + 1
            WHEN MOD(id, 2) != 0
            AND counts = id THEN id
            ELSE id - 1
        END
    ) AS id,
    student
FROM
    Seat,
    (
        SELECT
            COUNT(*) AS counts
        FROM
            Seat
    ) AS seat_cnts
ORDER BY
    id ASC;