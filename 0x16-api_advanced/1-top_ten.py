#!/usr/bin/python3
'''
    module contains the function top_ten
'''
import requests
from sys import argv


def top_ten(subreddit):
    '''
        Function returns the top ten posts for a given subreddit
    '''
    user = {'User-Agent': 'Lizzie'}
    URL = requests.get('https://www.reddit.com/r/{}/hot/.json?limit=10'
                       .format(subreddit), headers=user).json()
    try:
        for post in URL.get('data').get('children'):
            print(post.get('data').get('title'))
    except Exception:
        print(None)


if __name__ == "__main__":
    top_ten(argv[1])
