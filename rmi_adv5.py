#Anirudh's program for linear regression using gradient descent
import numpy
def cost(features,values,theta):
    m = len(values)
    h_x = numpy.dot(features,theta).flatten()
    squares = (h_x - values) ** 2
    cost = (1.0 / (2*m)) * squares.sum()
    return cost

def gradient_descent(features,values,theta,alpha,iterations):
    m = len(values)
    for i in range(iterations):
        h_x = numpy.dot(features,theta).flatten()

        temp0 = (h_x - values) * features[:, 0]
        temp1 = (h_x - values) * features[:, 1]
        
        theta[0][0] = theta[0][0] - alpha * (1.0 / m) * temp0.sum()
        theta[1][0] = theta[1][0] - alpha * (1.0 / m) * temp1.sum()
    return theta

def main():
    f = open('ex1data1.txt','r')
    cont = f.read().split('\n')
    data = []
    for line in cont:
        data.append(line.split(','))
    #print data
    f.close()
    m = len(data)
    x = [data[i][0] for i in range(m)]
    valu = [float(data[i][1]) for i in range(m)]
    features = numpy.ones(shape=(m,2))
    features[:,1] = x
    theta = numpy.zeros(shape=(2,1))
    values = numpy.ones(shape=(m,))
    values[:,] = valu
    iters = 15000
    alpha = 0.001
    print "Initial cost is "+str(cost(features,values,theta))
    theta = gradient_descent(features,values,theta,alpha,iters)
    print "Theta is "
    print theta
    print "Function is "
    print "f(x) = {:.5f}x + {:.5f}".format(theta[1][0],theta[0][0])
    print "Profit for a population of 45,000 is predicted to be(by using linear regression using gradient descent) "
    profit = (4.500 * theta[1][0]) + theta[0][0]
    profit *= 10000
    print "{:.5f}".format(profit)
main()
