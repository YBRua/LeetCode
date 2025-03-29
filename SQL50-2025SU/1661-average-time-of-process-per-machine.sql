SELECT
    tstart.machine_id AS machine_id,
    ROUND(AVG(tend.timestamp - tstart.timestamp), 3) AS processing_time
FROM
    Activity AS tstart
    JOIN Activity AS tend ON tstart.machine_id = tend.machine_id
    AND tstart.process_id = tend.process_id
WHERE
    tstart.activity_type = 'start'
    AND tend.activity_type = 'end'
GROUP BY
    tstart.machine_id