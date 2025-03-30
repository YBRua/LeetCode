SELECT
    activity_date as day,
    COUNT(DISTINCT user_id) AS active_users
FROM
    Activity
WHERE
    DATEDIFF ('2019-07-27', activity_date) BETWEEN 0 AND 29
GROUP BY
    day