def solution(brown, yellow):
    answer = []
    yel_x_y_axis_sum = (brown - 4) / 2
    yel_y = 0
    while True :
        yel_y += 1
        yel_x = yel_x_y_axis_sum - yel_y
        if yel_x * yel_y == yellow:
            answer.append(yel_x + 2)
            answer.append(yel_y + 2)
            break
    return answer