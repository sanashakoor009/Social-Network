
**Project Description**

We need to develop a console based social network application. Each User in the application has a unique ID and name. He may have other users in his friend list, having 10 friends at max. He has a list of pages which he has liked (10 pages at max). Each Page has a unique ID, title, list of posts it has shared and total number of people who have liked it. Each **Post** has a unique ID, description, no of likes, list of people who have liked it and shared date for example; a post is shared at 25th October 2017. A user or a page can share 10 posts at max. A post can have 10 comments at max. A comment is posted by a specific user. User can delete a comment on his posts. All the Users, Pages and Posts in the application are objects having IDs.



**Required Functionality:**

1. **Set Current User**
   1. Ask user about his ID and set him as current user of application. Now everything that we see in the system will be view of this user.
1. **View Home of Current User**
   1. Display posts of all friends shared in last 24 hours. For example,

|<p>Rabia Adnan shared “<Post ID - Post Description>”</p><p>- Ayesha Butt wrote: “Comment 1”</p><p>&emsp;&emsp;&emsp;- Ahmed Bilal wrote: “Comment 2” and so on</p><p></p><p>Asif Mustafa shared “<Post ID - Post Description>”</p><p>- Talha Javed wrote: “Comment 1”</p><p>&emsp;&emsp;&emsp;- Faisal Zaka wrote: “Comment 2”</p><p>&emsp;&emsp;&emsp;- Mannan Ahmed wrote: “Comment 3” and so on</p><p></p>|
| - |

1. Display posts of all his liked pages (or communities) shared in last 24 hours. For example 

|<p>FAST-NU shared “<Post ID – Post Description>”</p><p>- Ayesha Butt wrote: “Comment 1”</p><p>&emsp;&emsp;&emsp;- Ahmed Bilal wrote: “Comment 2” and so on</p><p></p><p>ICC – International Cricket Council shared “<Post ID – Post Description>”</p><p>- Talha Javed wrote: “Comment 1”</p><p>&emsp;&emsp;&emsp;- Faisal Zaka wrote: “Comment 2”</p><p>&emsp;&emsp;&emsp;- Mannan Ahmed wrote: “Comment 3” and so on</p><p></p>|
| - |
1. **Like a post**
   1. Ask user about ID of post and like it. A post can be liked by 10 users at max.
1. **View the list of People who liked a post**
   1. Take Post ID from user and display list of people who have liked it
1. **Comment on a Post**
   1. Take post ID and comment from the user and add this comment in the post
1. **View a Post**
   1. Take post ID and Display the post with its Comments
1. **Share a Post**
   1. Take post ID from user and share it
1. **View User’s Timeline**
   1. Display User Name
   1. Display user’s posts in his timeline
1. **View Friend List**
   1. Take ID of a user and display his friends list
1. **View Page**
   1. Take Page ID and display all its posts
1. **Search**
   1. Take a keyword from user and display all the People, Pages and Posts having this keyword in their name, title or description respectively.

**Important Instructions**

- You are not allowed to use global variables and functions
- Use best practices studied so far
- SocialNetworkData.txt contains list of users in following format

<user> <UserID> <UserName> <List of friends’ IDs delimited by -1> <List of Pages IDs delimited by -1>

<page> <Page ID> <Page Name>




**Sample Run:** You are required to bring following output (on your console window) at time of your evaluation.

|<p>Command:                Set current user “u07”</p><p>Abdullah Nadeem successfully set as Current User</p><p></p><p>Command:                Set current System Date 15 11 2017</p><p>System Date:            15/11/2017</p><p></p><p>Command:                View Friend List</p><p>-------------------------------------------------------------------------------------------------------------</p><p>Abdullah Nadeem – Friend List</p><p></p><p>u03 - Waheed Khan</p><p>u11 – Ahsan Ali</p><p>u12 – Kamal Subhani</p><p>---------------------------------------------------------------------------------------------------------------</p><p></p><p>Comand:                  View Liked Pages</p><p>---------------------------------------------------------------------------------------------------------------</p><p>Abdullah Nadeem – Liked Pages</p><p></p><p></p><p>P01 – Food Fusion</p><p>P02 – Al Jazeera English</p><p>P05 – Rumi Quotes</p><p>P09 – BBC News</p><p>---------------------------------------------------------------------------------------------------------------</p><p></p><p>Command:                View Home</p><p>---------------------------------------------------------------------------------------------------------------</p><p>Abdullah Nadeem – Home Page </p><p></p><p>//This is displaying posts of 15th and 14th November</p><p>--- Waheed Khan shared “Waheen Khan is excited about CP Project“</p><p>`                                        `Amna Akram wrote: “Best of Luck”</p><p>`                                        `Abdullah Nadeem wrote: “Interesting”</p><p></p><p>--- Ahsan Ali shared “Waiting for Weekend”</p><p>`                                        `Saad Ali wrote: “Any plans for Get Together?”</p><p>`                                        `Abdullah Nadeem wrote: “Yes BBQ”</p><p>`                                        `Nimra Batool wrote: “Lunch Buffet please”</p><p></p><p>--- Kamal Subhani shared “Waiting for Result”</p><p></p><p>--- Food Fusion shared “Food Fusion is making Kashmiri Chai (Pink Tea).”</p><p>`                                        `Amna Akram wrote: “Yummy”</p><p>`                                        `Ahsan Ali wrote: “One pink tea for me”</p><p></p><p>--- Al Jazeera English shared “Oil drilling in Alaska's indigenous communities is on the table again.”</p><p></p><p>--- Rumi Quotes shared “Be free of possessing things - Rumi”</p><p>`                                        `Kamal Subhani wrote: “Rumi is great”</p><p>---------------------------------------------------------------------------------------------------------------</p><p>Command:                  View TimeLine</p><p>---------------------------------------------------------------------------------------------------------------</p><p>Abdullah Nadeem –Time Line</p><p></p><p>--- “Happy Birthday to my dear Mom” … (14/11/2017)</p><p>`                                        `Waheed Khan wrote: “Happy Birthday Aunty”</p><p></p><p>--- “Happy Birthday to my dear Father” … (14/10/2017)</p><p>`                                        `Ahsan Ali wrote: “Happy Birthday Uncle”</p><p></p><p>---------------------------------------------------------------------------------------------------------------</p><p>Command:                   ViewLikedList(post01)</p><p></p><p>Post Liked By Users:</p><p>u01 – Amna Akram</p><p>---------------------------------------------------------------------------------------------------------------</p><p>Command:                   LikePost(post01)</p><p>Command:                   ViewLikedList(post01)</p><p></p><p>Post Liked By Users:</p><p>u01 – Amna Akram</p><p>u07 – Abdullah Nadeem</p><p>---------------------------------------------------------------------------------------------------------------</p><p>Command:                   PostComment(post04, Good Luck for your Result)</p><p>Command:                   ViewPost(post04)</p><p></p><p>Kamal Subhani shared “Waiting for Result”</p><p>`                                        `Abdullah Nadeem wrote: “Good Luck for your Result”</p><p>---------------------------------------------------------------------------------------------------------------</p><p>Command:                   PostComment(post08, Thanks for the wishes)</p><p>Command:                   ViewPost(post08)</p><p></p><p>--- “Happy Birthday to my dear Mom”</p><p>`                                        `Waheed Khan wrote: “Happy Birthday Aunty”</p><p>`                                        `Abdullah Nadeem wrote: “Thanks for the wishes”</p><p></p><p>---------------------------------------------------------------------------------------------------------------</p><p></p><p>Command:                   SharePost(post05)</p><p>Command:                  View TimeLine</p><p></p><p></p><p>Abdullah Nadeem –Time Line</p><p></p><p>--- “Happy Birthday to my dear Mom” … (14/11/2017)</p><p>`                                        `Waheed Khan wrote: “Happy Birthday Aunty”</p><p></p><p>--- “Happy Birthday to my dear Father” … (14/10/2017)</p><p>`                                        `Ahsan Ali wrote: “Happy Birthday Uncle”</p><p></p><p>--- “Food Fusion is making Kashmiri Chai (Pink Tea).” … (15/11/2017)</p><p>---------------------------------------------------------------------------------------------------------------</p><p>Command:                   ViewPage(p01)</p><p></p><p>Food Fusion</p><p>--- “Food Fusion is making Kashmiri Chai (Pink Tea).” … (14/11/2017)</p><p>`                                        `Amna Akram wrote: “Yummy”</p><p>`                                        `Ahsan Ali wrote: “One pink tea for me”</p><p></p><p>--- “Food Fusion is making Halwa Puri.” … (10/11/2017)</p><p>---------------------------------------------------------------------------------------------------------------</p><p>Command:                   Search(“Birthday”)</p><p></p><p>--- post08 - Abdullah Nadeem shared “Happy Birthday to my dear Mom”</p><p>--- post11 - Haris Muneer shared “Happy Birthday Ali Bhai”</p><p>--- p11 - Birthday Cakes</p><p></p><p>---------------------------------------------------------------------------------------------------------------</p><p>Command:                   Search(“Ali”)</p><p></p><p>--- u02 - Muhammad Ali</p><p>--- u06 - Saad Ali</p><p>--- u11 - Ahsan Ali</p><p>--- post11 - Haris Muneer shared “Happy Birthday Ali Bhai”</p><p>--- p12 - M Ali Jinnah</p><p></p><p></p>|
| - |


