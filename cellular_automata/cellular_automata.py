
def apply_rule(n):
    m = 2*n+3 # Ensure list has necessary size, note that the necessary
              # size grows with 2 per rule application. We also need 1
              # square to store the initial 'x' and one for each edge
              # s.t. we never have an inhabited edge.
    l = [False]*m # We represent uninhabited positions with False
    l[n+1] = True # We represent inhabited positions with True
    for i in range(0,n):
        lnew = [False]*m
        for j in range(1,m-1):
            if l[j]: #The rules
               lnew[j] = not(l[j-1] and l[j+1])
            else:
                lnew[j] = l[j-1] or l[j+1]
        l = lnew
    count = 0
    for e in l:
        if e:
            count += 1
    return(count)
        
print(apply_rule(253))
