c = 10
#reset()

def reset():
    global c
    c -= 10
    not_reset()
    print c


def not_reset():
    global c
    c -= 5
    print c
    
#not_reset()
reset()
print c

