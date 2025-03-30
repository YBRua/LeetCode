SELECT
    t1.category,
    COUNT(account_id) AS accounts_count
FROM
    (
        SELECT
            'Low Salary' category
        UNION ALL
        SELECT
            'Average Salary' category
        UNION ALL
        SELECT
            'High Salary' category
    ) AS t1
    LEFT JOIN (
        SELECT
            (
                CASE
                    WHEN income < 20000 THEN 'Low Salary'
                    WHEN income >= 20000 AND income <= 50000 THEN 'Average Salary'
                    ELSE 'High Salary'
                END
            ) AS category,
            account_id
        FROM
            Accounts
    ) AS t2 USING (category)
GROUP BY
    t1.category