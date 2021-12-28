from typing import List, Tuple


path = "M0 0 c-223 -18 -380 -153 -620 -535 -184 -293 -347 -364 -535 -235 -53 36 -82 65 -137 137 -48 63 -83 78 -130 55 -48 -25 -55 -56 -34 -149 57 -242 195 -455 371 -572 67 -44 133 -79 165 -87 8 -2 33 -10 55 -18 131 -47 372 -51 575 -11 260 53 421 132 590 291 l55 52 72 -68 c137 -129 269 -202 443 -246 148 -37 166 -40 310 -53 421 -37 745 141 914 503 47 100 90 258 82 299 -9 47 -33 67 -78 67 -30 0 -45 -6 -64 -27 -160 -182 -238 -236 -340 -234 -119 1 -240 92 -338 255 -193 318 -361 498 -518 553 -103 36 -326 33 -428 -6 -54 -21 -64 -21 -95 -4 -50 27 -194 42 -315 33"


def parse_position(x: str, y: str) -> complex:
    return int(x) + int(y) * 1j


def line_bezier(start: complex, end: complex) -> List[complex]:
    ctrl_pnt_rel_pos = (end - start) / 3  # control point relative position
    return [
        start,
        start + ctrl_pnt_rel_pos,
        end - ctrl_pnt_rel_pos,
        end,
    ]


data_points = path.split(" ")  # separating numbers

current_position = parse_position(data_points[0][1:], data_points[1])

current_command = ""  # svg path command

beziers: List[
    List[complex]
] = []  # a list of all the beziers (a bezier is a list of points)

# using iterator to continue multiple times
data_points_iter = iter(enumerate(data_points))


for index, data_point in data_points_iter:
    # checking for a new command
    if not (data_point[0].isdigit() or data_point[0] == "-"):
        current_command = data_point[0]
        data_point = data_point[1:]

    # translation - moving current position
    if current_command == "M":
        current_position = parse_position(data_point, data_points[index + 1])
        next(data_points_iter)
    elif current_command == "m":
        current_position = parse_position(data_point, data_points[index + 1])
        next(data_points_iter)

    # bezier curves
    elif current_command == "c":
        bezier_points: List[complex] = [
            current_position,
            current_position + parse_position(data_point, data_points[index + 1]),
        ]  # points for the current bezier

        for relative_index in [2, 4]:
            # calculating control points
            bezier_points.append(
                current_position
                + parse_position(
                    data_points[index + relative_index],
                    data_points[index + relative_index + 1],
                )
            )

        beziers.append(bezier_points)

        current_position = bezier_points[-1]

        for i in range(5):
            next(data_points_iter)  # continuing to the next data point

    elif current_command == "l":
        bezier_end_point = current_position + parse_position(
            data_point, data_points[index + 1]
        )
        beziers.append(line_bezier(current_position, bezier_end_point))
        current_position = bezier_end_point

        next(data_points_iter)


# printing a c array of the beziers
print("{")
for bezier in beziers:
    print(" Bezier(new Vector[4]{")
    for index, point in enumerate(bezier):
        comma = ", " if index != 3 else ""
        print(f"Vector({point.real}, {point.imag}){comma}", end="")
    print("}),", end="")
    print()

print("};")
