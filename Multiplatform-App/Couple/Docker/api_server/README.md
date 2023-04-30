docker build -t couple_api_server .
docker rm couple_api_server
docker run --network couple-network -p 5001:5000 --name couple_api_server couple_api_server 
docker start couple_api_server 