#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

struct Vector2 {
  double x=0, y=0;
  Vector2() : x(0), y(0){};
  Vector2(double x, double y) : x(x), y(y){};
  Vector2(const Vector2& v) = default;

  // unary operations
  Vector2 operator-() const { return {-x, -y}; }
  Vector2 operator+() const { return {x, y}; }

  // binary operations
  Vector2 operator-(const Vector2& rhs) const { return {x - rhs.x, y - rhs.y}; }
  Vector2 operator+(const Vector2& rhs) const { return {x + rhs.x, y + rhs.y}; }
  Vector2 operator*(const double& rhs) const { return {x * rhs, y * rhs}; }
  friend Vector2 operator*(const double& lhs, const Vector2& rhs) { return {lhs * rhs.x, lhs * rhs.y}; }
  Vector2 operator/(const double& rhs) const { return {x / rhs, y / rhs}; }
  Vector2 operator/(const Vector2& rhs) const { return {x / rhs.x, y / rhs.y}; }
  bool operator!=(const Vector2& rhs) const { return (*this - rhs).sqrMagnitude() >= 1.0e-6; };
  bool operator==(const Vector2& rhs) const { return (*this - rhs).sqrMagnitude() < 1.0e-6; };

  // assignment operation
  Vector2& operator=(Vector2 const& rhs) = default;
  Vector2& operator=(Vector2&& rhs) = default;

  // compound assignment operations
  Vector2& operator+=(const Vector2& rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }
  Vector2& operator-=(const Vector2& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
  }
  Vector2& operator*=(const double& rhs) {
    x *= rhs;
    y *= rhs;
    return *this;
  }
  Vector2& operator/=(const double& rhs) {
    x /= rhs;
    y /= rhs;
    return *this;
  }
  Vector2& operator*=(const Vector2& rhs) {
    x *= rhs.x;
    y *= rhs.y;
    return *this;
  }
  Vector2& operator/=(const Vector2& rhs) {
    x /= rhs.x;
    y /= rhs.y;
    return *this;
  }

  double sqrMagnitude() const { return x * x + y * y; }
  double getMagnitude() const { return sqrt(sqrMagnitude()); }
  static double getMagnitude(const Vector2& vector) { return vector.getMagnitude(); }

  static double Distance(const Vector2& a, const Vector2& b) { return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); };
  double Distance(const Vector2& b) const { return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y)); };
  static double DistanceSquared(const Vector2& a, const Vector2& b) { return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y); };
  double DistanceSquared(const Vector2& b) const { return (x - b.x) * (x - b.x) + (y - b.y) * (y - b.y); };

  static Vector2 normalized(const Vector2& v) { return v.normalized(); };
  Vector2 normalized() const {
    auto magnitude = getMagnitude();

    // If the magnitude is not null
    if (magnitude > 0.)
      return Vector2(x, y) / magnitude;
    else
      return {x, y};
  };

  static const Vector2 zero;
};

const Vector2 Vector2::zero = {0, 0};

struct Boid {
  Boid(const Vector2& pos, const Vector2& vel): position(pos), velocity(vel){};
  Boid():position({0,0}), velocity({0,0}){};
  Vector2 position;
  Vector2 velocity;
};

struct Cohesion {
  double radius;
  double k;

  Vector2 ComputeForce(const vector<Boid>& boids, int boidAgentIndex) {
    auto agent = boids[boidAgentIndex];
    Vector2 centerOfMass = {0,0};
    int numberOfNeighbors = 0;
    for(int i = 0; i < boids.size(); i++){
      if(i==boidAgentIndex)
        continue;
      auto vec = boids[i].position - agent.position;
      auto magnitude = vec.getMagnitude();
      if(magnitude < radius && vec != Vector2::zero) {
        centerOfMass += vec;
        numberOfNeighbors++;
      }
    }
    if(numberOfNeighbors>0){
      return k * ((centerOfMass/numberOfNeighbors)/radius);
    }
    else
      return {};
  }
};

struct Alignment {
  double radius;
  double k;

  Vector2 ComputeForce(const vector<Boid>& boids, int boidAgentIndex) {
    auto agent = boids[boidAgentIndex];
    Vector2 avgVelocity = {0,0};
    int numberOfNeighbors = 0;
    for(const auto & boid : boids){
      auto displacementVec = boid.position - agent.position;
      auto magnitude = displacementVec.getMagnitude();
      if(magnitude < radius) {
        avgVelocity += boid.velocity;
        numberOfNeighbors++;
      }
    }
    if(numberOfNeighbors>0){
      return k * (avgVelocity/numberOfNeighbors);
    }
    else
      return {};
  }
};

struct Separation {
  double radius;
  double k;
  double maxForce;

  Vector2 ComputeForce(const vector<Boid>& boids, int boidAgentIndex) {
    auto agent = boids[boidAgentIndex];
    Vector2 avg = {0,0};
    int numberOfNeighbors = 0;
    for(int i=0;i<boids.size();i++){
        if(i==boidAgentIndex)
          continue;
        auto displacementVec = boids[i].position - agent.position;
        auto magnitude = displacementVec.getMagnitude();
        if(magnitude < radius && displacementVec != Vector2::zero) {
          auto displacementVecNorm = displacementVec / magnitude;
          avg += displacementVecNorm;
          numberOfNeighbors++;
        }
    }
    if(avg.getMagnitude() > maxForce)
      return avg.normalized() * maxForce;
    else
      return avg;
  }
};

int main() {
  // Variable declaration
  double rc, rs, Fsmax, ra, Kc, Ks, Ka;
  int numberOfBoids;
  string line; // for reading until EOF
  vector<Boid> currentState, newState;
  // Input Reading
  cin >> rc >> rs >> Fsmax >> ra >> Kc >> Ks >> Ka >> numberOfBoids;
  for (int i = 0; i < numberOfBoids; i++)
  {
    Boid b;
    cin >> b.position.x >> b.position.y >> b.velocity.x >> b.velocity.y;
    //cout << "b.y: " << b.y << endl;
    currentState.push_back(b);
    newState.push_back(b);
  }
  // Final input reading and processing
  while (getline(cin, line)) { // game loop
    currentState = newState;
    double deltaT = stod(line);
    // cout << "== Start Line Read. deltaT: " << deltaT << " ==" << endl;
    vector<Vector2> allForces;  // a vector of the sum of forces for each boid.
    // Compute Forces
    for (int i = 0; i < numberOfBoids; i++)  // for every boid
    {
      // cout << ">-> For Every Boid " << i << endl;
      double totalForceX = 0.0, totalForceY = 0.0, cohesionTotalX = 0.0, cohesionTotalY = 0.0,
             separationTotalVX = 0.0, separationTotalVY = 0.0, alignmentTotalVX = 0.0,
             alignmentTotalVY = 0.0;
      int cohesionTotalBoids = 0, alignmentTotalBoids = 0;
      for (int j = 0; j < N; j++)  // for every boid combination. Pre-processing loop.
      {
        // cout << ">-> >-> For Every Boid Combination " << j << endl;
        //  Pre-Process Cohesion Forces
        if (i != j
            && get_distance(allBoids[i].x, allBoids[i].y, allBoids[j].x, allBoids[j].y) <= rc) {
          // cout << "Cohesion Force Found" << endl;
          cohesionTotalX += allBoids[j].x;
          cohesionTotalY += allBoids[j].y;
          cohesionTotalBoids++;
        }
        // Pre-Process Separation Forces
        if (i != j
            && get_distance(allBoids[j].x, allBoids[j].y, allBoids[i].x, allBoids[i].y) <= rs) {
          // cout << "Separation Force Found" << endl;
          pair<double, double> nvANi
              = get_normalized_vector(allBoids[j].x, allBoids[j].y, allBoids[i].x, allBoids[i].y);
          pair<double, double> vANi
              = get_vector(allBoids[j].x, allBoids[j].y, allBoids[i].x, allBoids[i].y);
          // cout << "nvANI. x: " << nvANi.first << " y: " << nvANi.second << " vANI. x: " << vANi.first << " y: " << vANi.second << endl;
          if (vANi.first != 0) {
            separationTotalVX += nvANi.first / abs(vANi.first);
          }
          if (vANi.second != 0) {
            separationTotalVY += nvANi.second / abs(vANi.second);
          }
          // cout << "nvANi.first: " << nvANi.first << " vANi.first: " << vANi.first << " nvANi.first/vANi.first: " << nvANi.first/vANi.first << endl;
        }
        // Pre-Process Alignment Forces
        if (get_distance(allBoids[i].x, allBoids[i].y, allBoids[j].x, allBoids[j].y) <= ra) {
          // cout << "Alignment Force Found" << endl;
          alignmentTotalVX += allBoids[j].vx;
          alignmentTotalVY += allBoids[j].vy;
          alignmentTotalBoids++;
          // cout << "alignmentTotalVX: " << alignmentTotalVX << endl;
        }
      }
      // Process Cohesion Forces
      if (cohesionTotalBoids > 0) {  // If a cohesion force was found
        pair<double, double> cohesionVector
            = get_vector(allBoids[i].x, allBoids[i].y, cohesionTotalX / cohesionTotalBoids,
                         cohesionTotalY / cohesionTotalBoids);
        totalForceX += (cohesionVector.first / rc) * Kc;
        totalForceY += (cohesionVector.second / rc) * Kc;
        // cout << "* cohesion force Y: " << ((cohesionVector.second/rc) * Kc) << endl;
      }
      // Process Separation Forces
      if (sqrt(pow(separationTotalVX, 2) * pow(separationTotalVY, 2))
          <= Fsmax)  // if total force is NOT greater than limit, use as is.
      {
        totalForceX += (separationTotalVX * Ks);
        // cout << "S totalForceY: "  << totalForceY << endl;
        totalForceY += (separationTotalVY * Ks);
        // cout << "* (1)separation Force Y: " << totalForceY << endl;
      } else {  // else normalize and multiply by limit
        pair<double, double> normalized = normalize_vector(separationTotalVX, separationTotalVY);
        totalForceX += normalized.first * Fsmax * Ks;
        totalForceY += normalized.second * Fsmax * Ks;
        // cout << "* (2)separation Force Y: " << (normalized.second * Fsmax * Ks) << endl;
      }
      // Process Alignment Forces
      if (alignmentTotalBoids > 0) {
        totalForceX += alignmentTotalVX / alignmentTotalBoids * Ka;
        // cout << "(A) totalForceX: "  << totalForceX << endl;
        totalForceY += alignmentTotalVY / alignmentTotalBoids * Ka;
        // cout << "* total Alignment Force X: " << (alignmentTotalVX/alignmentTotalBoids * Ka) << " totalForceX " << totalForceX << endl;
      }
      // cout << "total Force X in the end: " << totalForceX << endl;
      // cout << "* total Force Y in the end: " << totalForceY << endl;
      //  Add total forces of 1 boid to forces vector.
      allForcesX.push_back(totalForceX);
      allForcesY.push_back(totalForceY);
    }
    // Tick Time and Output
    cout << fixed << setprecision(3);  // set 3 decimal places precision for output
    for (int i = 0; i < N; i++)        // for every boid
    {
      // cout << "FORCES X: " << allForcesX[i] << " Y: " << allForcesY[i] << endl;
      allBoids[i].vx += allForcesX[i] * deltaT;
      allBoids[i].vy += allForcesY[i] * deltaT;
      allBoids[i].x += allBoids[i].vx * deltaT;
      allBoids[i].y += allBoids[i].vy * deltaT;
      cout << allBoids[i].x << " " << allBoids[i].y << " " << allBoids[i].vx << " "
           << allBoids[i].vy << endl;
    }
  }

  return 0;
}
