select
    t1.*,
    if (
        (
            (t1.x + t1.y) > t1.z
            and (t1.x + t1.z) > t1.y
            and (t1.y + t1.z) > t1.x
        ),
        'Yes',
        'No'
    ) as triangle
from
    Triangle t1
