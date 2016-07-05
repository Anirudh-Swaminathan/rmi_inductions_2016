import Queue

world = [["0" for i in range(51)] for j in range(51)]
n = 0
m = 0

start_x = -1
start_y = -1

q = Queue.Queue()
mark = [[False for i in range(51)] for j in range(51)]
xparent = [["0" for i in range(51)] for j in range(51)]
yparent = [["0" for i in range(51)] for j in range(51)]
path = Queue.LifoQueue()

def bfs(world,m,n,x,y):
    reached = False
    end_x = -1
    end_y = -1
    paths = [["0" for i in range(51)] for j in range(51)]
    mark[x][y] = True
    q.put([x,y])
    while not q.empty():
        cur = q.get()
        #print "Visited world["+str(cur[0])+"]["+str(cur[1])+"] which is "+str(world[cur[0]][cur[1]])
        if world[cur[0]][cur[1]] == 'g':
            end_x = cur[0]
            end_y = cur[1]
            reached = True
            break
        if cur[0] != 0:
            if mark[cur[0]-1][cur[1]] == False and world[cur[0]-1][cur[1]]!='1':
                mark[cur[0]-1][cur[1]] = True
                xparent[cur[0]-1][cur[1]] = cur[0]
                yparent[cur[0]-1][cur[1]] = cur[1]
                paths[cur[0]-1][cur[1]] = "UP"
                q.put([cur[0]-1,cur[1]])
        if cur[0]!=m-1:
            if mark[cur[0]+1][cur[1]] == False and world[cur[0]+1][cur[1]]!='1':
                mark[cur[0]+1][cur[1]] = True
                xparent[cur[0]+1][cur[1]] = cur[0]
                yparent[cur[0]+1][cur[1]] = cur[1]
                paths[cur[0]+1][cur[1]] = "DOWN"
                q.put([cur[0]+1,cur[1]])
        if cur[1]!=0:
            if mark[cur[0]][cur[1]-1] == False and world[cur[0]][cur[1]-1]!='1':
                mark[cur[0]][cur[1]-1] = True
                xparent[cur[0]][cur[1]-1] = cur[0]
                yparent[cur[0]][cur[1]-1] = cur[1]
                paths[cur[0]][cur[1]-1] = "LEFT"
                q.put([cur[0],cur[1]-1])
        if cur[1]!=n-1:
            if mark[cur[0]][cur[1]+1] == False and world[cur[0]][cur[1]+1]!='1':
                mark[cur[0]][cur[1]+1] = True
                xparent[cur[0]][cur[1]+1] = cur[0]
                yparent[cur[0]][cur[1]+1] = cur[1]
                paths[cur[0]][cur[1]+1] = "RIGHT"
                q.put([cur[0],cur[1]+1])
    print_path(world,reached,end_x,end_y,paths)
    
def inpu():
    s = map(int,raw_input().split())
    m = s[0]
    n = s[1]
    for i in range(m):
        l = raw_input().split()
        for j in range(len(l)):
            world[i][j] = l[j]
            if l[j] == 's':
                start_x = i
                start_y = j
    operate(world,m,n,start_x,start_y)
    
def operate(world,m,n,start_x,start_y):
    bfs(world,m,n,start_x,start_y)

def print_path(world,reached,end_x,end_y,paths):
    if reached == True:
        a1 = end_x
        b1 = end_y
        x = 0
        while world[a1][b1] != 's':
            path.put(paths[a1][b1])
            x+=1
            p = a1
            a1 = xparent[a1][b1]
            b1 = yparent[p][b1]
        print "The path is "
        while not path.empty():
            print path.get()
        print "The number of steps that must be taken to reach the goal is "+str(x)
    else:
        print "Sorry, No path exists to the goal"
def main():
    inpu()
if __name__ == '__main__':
    main()
