SELECT
    p.product_id,
    ROUND(SUM(p.price * s.units) / SUM(s.units), 2) AS average_price
FROM
    Prices AS p
    JOIN UnitsSold AS s ON p.product_id = s.product_id
WHERE
    s.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY
    p.product_id