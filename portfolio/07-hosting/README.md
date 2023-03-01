# Hosting

There are many hosting options and solutions to match each need. Lets cover some options here.

# Options low code
- Google sites - My preference

Other notable options:
- Godaddy
- Wordpress
- Wix
- Squarespace

The problem with those are they require payments to be fully functional, so if you want to go deep and have mor freedom, we are going to cover other options.

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

# CDN and DNS Management

I highly recommend you to use Cloudflare as you DNS nameserver, so you can cache your website results for faster loading. But you can use your own nameserver provider by your domain name registrar.

DNS stands for Domain Name System, which is a system that translates domain names into IP addresses. When you type a domain name into your web browser, such as "www.example.com," your computer sends a request to a DNS server to resolve the domain name into an IP address, such as "192.0.2.1." The IP address is then used to establish a connection with the web server that hosts the website you are trying to access.

DNS plays a crucial role in hosting because it enables users to access websites using domain names instead of IP addresses. This makes it easier for users to remember and find websites. DNS also allows websites to change servers or IP addresses without affecting the user experience, as long as the DNS records are updated properly.

In hosting, DNS is important because it determines which server is responsible for hosting a particular website. DNS records can be configured to point to different servers depending on factors such as geographic location, server load, and failover. Hosting providers typically offer DNS management tools to help users configure and manage their DNS records.

# Homework

The goal is to have as website up and running for your portfolio.

Here goes my preferable way for hosting anything. With that you can host microservices, game services, serve API, static and dynamic websites and much more. It can be tricky but lets setup it now.

- Oracle cloud - Free forever - Virtual Machine with 4vCPU, 24GB ram, 200GB storage. https://www.youtube.com/watch?v=NKc3k7xceT8 watch up to 5:38 time
- Coolify - Your private Software as a Service (SAAS) manager - https://youtu.be/Jg6SWqyvYys?t=125 starts from minute 2:00
- CI/CD - to your remote machine https://www.youtube.com/watch?v=Uj7F3hdgmEo
- Cloudflare DNS - set your domain to point to your DNS - https://www.youtube.com/watch?v=XQKkb84EjNQ 
- Install Wordpress via coolify interface(new resource, new service) and use your own DNS. Or host your page statically https://www.youtube.com/watch?v=CfdPyASUSkI&

Talk with me if you dont have a domain and want to use my infrastructure temporarily.

I am assuming you wont have a huge traffic, but you have a complex combination of services. In the complex cases
and if you want to make your life easier and cheaper,my suggestion for hosting would be oracle cloud with arm cpu. 
They offer for free a virtual machine with 200gb storage, 4vcpus, 24gb ram for free at this date of 2022/12 
[tutorial](https://www.youtube.com/watch?v=NKc3k7xceT8). In this scenario, I recommend using https://coolify.io/ as 
your deployment management system, just pay attention that this machine is running in an arm cpu. With this 
combination, you can manage everything easily in one place for free. This is not ideal, because you wont have 
backups, but it is good enough for most scenarios.

If you have plenty of money or your website have high traffic, I recommend you to use Kubernetes to orchestrate 
every microservice.