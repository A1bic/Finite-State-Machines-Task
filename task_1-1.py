#a = ""
a = input("Введите строку для автомата: ")


current_state = 'q0'
for i in a:
    if (current_state == "q0"):
        if (i == "a"):
            current_state = "q1"
        elif (i == "b"):
            current_state = "q0"
        else:
            current_state = "nothing"
    elif (current_state == "q1"):
        if (i == "a"):
            current_state = "q1"
        elif (i == "b"):
            current_state = "q2"
        else:
            current_state = "nothing"
    elif (current_state == "q2"):
        if (i == "a"):
            current_state = "q1"
        elif (i == "b"):
            current_state = "q0"
        else:
            current_state = "nothing"
    elif (current_state == "nothing"):
        break

if (current_state == "q2"):
    print("Автомат принял строку")
else:
    print("Автомат не принял строку")
