# Hosting

There are many hosting options and solutions to match each need. Lets cover some options here.

# Static HTML with Static Data
If what you want to serve is static hosting, your content is only frontend and do not require backend, you can use 
github pages, google firebase, S3 bucket hosting or many others. This is the easiest approach. 
- In this scenario you will be able to store only pre-generated html and static files;
- This is useful even if you use blogs that changes rarely, you would have to redeploy your page for every change.

# Static HTML with Dynamic Data
If your html is static and need backend services that are rarely called, you can go with cloud functions, my 
suggestions here are google cloud run and aws amplify or even firebase functions. If you use nextjs website, check 
vercel or netlify hosting services. 
- The deploys are easy;
- It can be very expensive if you hit high traffic, but it will remain free if you dont hit the free tiers;
- You will have to pay attention to your database management;

# Dynamic HTML with Dynamic Data
If your website generate content dynamically such as Wordpress blogs or any custom made combination with next or 
anything.
- There is many "cheap hosting" solutions that are mostly bad performant(it can reach more than 10s to answer a 
  request). You have to avoid them to make your user enjoy the visit;
- Management can go as hard as possible, but the results can be awesome;
- It can be really expensive;

I am assuming you wont have a huge traffic, but you have a complex combination of services. In the complex cases
and if you want to make your life easier and cheaper,my suggestion for hosting would be oracle cloud with arm cpu. 
They offers for free a virtual machine with 200gb storage, 4vcpus, 24gb ram for free at this date of 2022/12 
[tutorial](https://www.youtube.com/watch?v=NKc3k7xceT8). In this scenario, I recommend using https://coolify.io/ as 
your deployment management system, just pay attention that this machine is running in an arm cpu. With this 
combination, you can manage everything easily in one place for free. This is not ideal, because you wont have 
backups, but it is good enough for most scenarios.

If you have plenty of money or your website have high traffic, I recommend you to use Kubernetes to orchestrate 
every microservice.