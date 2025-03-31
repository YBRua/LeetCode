SELECT
    user_id AS id,
    COUNT(*) AS num
FROM
    (
        (
            SELECT DISTINCT
                requester_id AS user_id
            FROM
                RequestAccepted
        )
        UNION
        (
            SELECT DISTINCT
                accepter_id AS user_id
            FROM
                RequestAccepted
        )
    ) AS Users
    JOIN RequestAccepted ON user_id = requester_id
    OR user_id = accepter_id
GROUP BY
    user_id
ORDER BY
    COUNT(*) DESC
LIMIT
    1