SELECT
    w1.id
FROM
    Weather w1
    JOIN Weather w2 ON DATEDIFF (w1.RecordDate, w2.RecordDate) = 1
WHERE
    w2.Temperature < w1.Temperature