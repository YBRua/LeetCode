SELECT
    p.product_id,
    ROUND(
        IFNULL (SUM(p.price * s.units) / SUM(s.units), 0),
        2
    ) AS average_price
FROM
    Prices AS p
    LEFT JOIN UnitsSold AS s ON p.product_id = s.product_id
WHERE
    s.purchase_date BETWEEN p.start_date AND p.end_date
    OR s.purchase_date IS NULL
GROUP BY
    p.product_id