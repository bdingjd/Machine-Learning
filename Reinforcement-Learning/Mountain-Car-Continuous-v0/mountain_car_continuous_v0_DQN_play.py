import gym
import numpy as np 
import math
import torch
import torch.nn as nn 
import argparse
ACTION_SIZE = 21

class Net(nn.Module):
    def __init__(self, obs_size, ACTION_SIZE):
        super(Net, self).__init__()
        self.net = nn.Sequential(
            nn.Linear(obs_size, 32),
            nn.ReLU(),

            nn.Linear(32, 64),
            nn.ReLU(),


            nn.Linear(64, ACTION_SIZE)
        )

    def forward(self, x):
        return self.net(x)  

if __name__ == "__main__":
    env = gym.make('MountainCarContinuous-v0') 

    parser = argparse.ArgumentParser()
    parser.add_argument("-m", "--model", required=True, help="Model file to load")
    args = parser.parse_args()
    net = Net(env.observation_space.shape[0], ACTION_SIZE) 
    net.load_state_dict(torch.load(args.model, map_location=lambda storage, loc: storage))
    print(net)
    
    obs = env.reset()  
    act = np.zeros((1,),dtype = float)
    while True:  
        env.render()
        state_v = torch.FloatTensor([obs])
        target = net(state_v)  
        index = target.max(dim = -1)[1] 
        index_v = index.numpy()
        act[0] = (index_v-int(ACTION_SIZE/2))/float(int(ACTION_SIZE/2))
        obs, reward, done, _ = env.step(act) 
        if done: 
            obs = env.reset()
