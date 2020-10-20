# FocalMix: Semi-Supervised Learning for 3D Medical Image Detection
## 1. Introduction

- raw medical image가 annotation이 거의 없더라도 딥러닝 모델의 진단 정확도를 향상시키는 연구 필요
- 최신 **Semi-Supervised Learning** 대부분은 레이블이 없는 데이터에 정의된 axiliary loss term ( e.g., **consistency regularization term**) 또는 레이블이 있는 데이터와 없는 데이터의 interpolation을 loss에 더하는 방식
- 아직 의료 영상에 SSL을 적용하기에는 무리가 있음
- 최신 SSL 프레임 워크는 일반적으로 loss function이 soft label(e.g., 클래스에 대한 smooth한 확률)을 처리할 수 있도록 요구하는 반면, 대부분의 **one-stage object detection** 계열 병변 탐지 모델은 자연스러운 확장이 없는 **focal loss**를 사용함
- 또한 최신 SSL은 평균 앙상블을 사용하여 레이블이 없는 데이터에 대한 **psudo-label**을 얻음. 그럼에도 detection model에 의해 예측된 bounding box의 평균을 취하기는 어려움
- medical image augmentation 관련 연구 적음

### Propose

- 왜곡 된 분포(대부분의 object detection model에서 발생하는 클래스 불균형과 유사한)를 가진 soft-target train label를 허용하는 focal loss의 일반화 제안 (**3.1. Soft-target Focal Loss**)
- augmented image patch의 anchor level 앙상블을 활용하는 target prediction 전략 제안 (**3.2. Anchor-level Target Prediction**)
- MixUp augmentation은 의료 이미지 detection task의 특성에 비추어 이미지 수준 및 객체 수준 모두에서 적합함 (**3.3. MixUp Augmentation for Detection**)
- annotation이 있는 데이터 셋이 이미 있을 때 FocalMix가 여전히 supervised learning의 성능을 향상시킬 수 있음(**4.4. Ablation Study**)

### Main Contributions

- medical image detection에서 FocalMix와 새로운 semi-supervised learning  제안
- medical image detection에서 SSL의 문제를 최초로 연구함
- 제안된 semi-supervised 접근이 fully-supervised 접근법의 성능을 크게 향상시킬 수 있음을 보여줌

## 2. Background and Preliminaries

### 2.1. Object Detection in 3D Medical Images

- 서로 다른 스케일의 병변을 탐지하기 위해 대부분의 연구에서는 Feature Pyramid Network의 3D 변형과 같은 anchor 기반 detector 채택
- focal loss는 foreground-background class의 불균형을 극복하기 위해 사용됨

![2FEF95E4-C8F1-4288-BEA5-E7F226D1D457](https://user-images.githubusercontent.com/51358226/96603408-f4b72a00-132e-11eb-9cc4-db41080e7b67.jpeg)

- (a)는 anchor에 target을 할당하는 예. grid는 anchor box가 정의된 output feature map을 나타내며 grid의 각 bin은 feature map의 한 점에 해당. 분홍색은 ground-truth bounding box. 주황색은 positive anchor이고 파란색은 negative anchor
- (b)는 target prediction에 사용되는 augmentation 방법의 예. 이미지 patch에는 flip augmentation을 사용하고 각 anchor의 확률을 예측. 그 다음 patch와 anchor를 역변환

### 2.1.1. Anchor boxes

- anchor box는 target object 와 이미지에 밀집된 미리 정의된 bounding box
- **Faster RCNN**에 따라, anchor box는 다른 shape의 object를 포착하기 위해 다른 스케일과 종횡비를 갖도록 설정됨.
- 각 anchor는 detector의 feature map에 있는 픽셀에 해당하며 receptive field와 동일한 center를 공유함
- convolution layer로 구현된 mini-network는 슬라이딩 윈도우 방식으로 각 anchor에 대한 예측을 수행하는 데 사용됨
- training 중 anchor box는 object가 ground-truth bounding box와 overlap된 경우에 positive anchor로 간주
- 네트워크는 출력으로 각 anchor box에 대한 confidence score 와 offset을 예측
- **Feature Pyramid Network**는 작은 object의 detection 성능을 향상시키기 위해 multi scale feature map에 anchor를 배치함
    - "Learning to unlearned feature for segmentation"
    
### 2.1.3. Focal Loss

- negative anchor에 비해 positive anchor가 적은 문제를 극복하기 위해

  ![1909ED17-9E78-4C42-A117-7EC8931D5165](https://user-images.githubusercontent.com/51358226/96603910-760ebc80-132f-11eb-9805-acb6c5fe6fef.jpeg)


    - $\alpha_t$ : 다른 클래스에 대한 가중치
    - $\gamma$ : positive anchor와 negative anchor의 균형을 맞추기 위한 변수
    - $p_t$ : confident sample을 down-weight하여 less confident 모델에 모델을 집중시킴
    
### 2.2. Semi-supervised Learning

- 레이블이 없는 데이터를 사용하여 모델 성능을 향상시키는 것이 목표
- MixMatch
    - entropy minimization, consistency regularization, MixUp augmentation
    - 레이블이 없는 데이터의 target prediction과 MixUp augmentation으로 이루어짐
    - 클래스 레이블이 거의 변하지 않는 이미지 내 data point의 stochastic transformation set을 정의해야 함
    - MixMatch는 레이블이 없는 각 training sample $u$의 $K$ augmented instance $\hat{\mu_k}$에 대해 $\theta$로 매개변수화 된 현재 모델에 의한 평균 예측 앙상블을 레이블에 대한 guesses 로 사용함

    ![185ABB33-23F2-428E-94C9-13E34728B533](https://user-images.githubusercontent.com/51358226/96603996-8de64080-132f-11eb-921d-f3b00faeb624.jpeg)

    guessed label은 training target으로 사용되기 전에 sharpening operator에 의해 변환됨

    L 클래스의 i 번째는 아래와 같이 정의

    ![A63C5CDE-CDC6-47B2-96EB-D56B3E136461](https://user-images.githubusercontent.com/51358226/96604089-abb3a580-132f-11eb-8e16-08ebb3d8acad.jpeg)

    - $T$ → 0 으로 output이 one-hot-vector 가 됨
    - sharpening operation은 모델이 암시적으로 레이블이 없는 데이터에 대해 낮은 엔트로피 예측을 출력하도록 강제함
    - 레이블이 없는 데이터에 대한 training target을 사용할 수 있게 되면 MixMatch는 레이블이 있는 데이터와 레이블에 없는 데이터 모두에 대해 MixUp augmentation을 활용함
        - "Mixup: Beyond empirical risk minimization", ICVR 2018
    - $(x, y)$가 있는 레이블이 지정된(또는 레이블이 없는) data point가 주어지면 MixUp augmentation은 레이블이 지정된 다른 training example $(x^{'}, y^{'})$와 stochastic linear interpolation 을 생성함

    ![70C98529-6B3B-4BA4-A5FB-3AE210C09CBE](https://user-images.githubusercontent.com/51358226/96604155-be2ddf00-132f-11eb-9e69-c293955364bd.jpeg)

    - 레이블이 있는 데이터와 없는 데이터 모두에서 supervision signal 을 사용하여 augmented된 training example 들을 얻은 다음 supervised objectives를 사용하여 모델 매개 변수를 학습할 수 있음

## 3. Methodology

- focal loss 의 일반화를 통해 SSL 프레임 워크에서 발생하는 soft training target을 대상으로 detection model을 훈련

![D62D2532-688E-4E6B-A9F5-20A41B5D276B](https://user-images.githubusercontent.com/51358226/96604221-d140af00-132f-11eb-97ef-333d9f663dc2.jpeg)

### 3.1. Soft-target Focal Loss

- 대부분 분류 작업에 초점을 맞추고 cross entropy loss가 soft label을 자연스럽게 처리할 수 있기 때문에 SSL 연구에서 문제로 제기되는 경우는 거의 없음
- 그러나 최신 object detection은 cross entropy loss 에 두 가지 가중치 항  $\alpha(y)$, $\beta(y, p) = (1-p_t)^\gamma$ 를 추가하는 focal loss를 사용함
- 두 가중치 항은 모두 클래스 레이블에 의존하며 $y$가 0과 1 사이의 연속적인 값을 가질 수 있다면 trivial extension이 없어 SSL 을 직접 적용할 수 없음
- 제안된 방식은 두 가중치 항을 soft target의 case에 맞게 일반화 함
- 첫 번째 항 $\alpha(y)$는 원래 클래스 불균형을 위해 고안되었으며 일반적으로 클래스 $y$의 역 빈도수에 비례함
    - 빈도가 적은 positive example에 대한 $\alpha$는 빈도가 많은 negative example에 대한 $\alpha$가 total loss를 지배하는 것을 방지하기 위해 더 큼.
    - 따라서 $\alpha(y)$는 $y$의 확률밀도함수에 반비례해야하지만 모델 학습 방법에 따라 밀도 추정을 수행하는 것은 계산상으로는 불가능함

        → $y$의 밀도 함수는 $1/y$와 거의 같은 비율로 decay 되고 0과 1의 density는 하이퍼 파라미터로 처리되어 $\alpha_0, \alpha_1$로 표시된 교차 검증에 의해 결정됨

    - 이 가정 하에서 soft label에 대한 $\alpha(y)$의 형태를 $\alpha(y)=\alpha_0 + y(\alpha_1-\alpha_0)$로 도출함
- 두 번째 항 $(1-p_t)^\gamma$는 detection 모델의 training 과정에서 널리 퍼져있는 background anchor와 같은 쉬운 example을 down-weight하는 데 사용됨
    - confidence score $p_t$와 목표값 사이의 불일치로 해석
    - training example의 hardness를 어느 정도 측정할 수 있음
    - $\beta(y, p)=|y-p|^\gamma$ → 예측과 training target의 차이로 soft-target label로 일반화 할 수 있음
- SSL을 위한 soft-target focal loss
    - $SFL(p)=[\alpha_0+y(\alpha_1-\alpha_0)]\cdot|y-p|^\gamma \cdot CE(y, p)$
    - where $CE(y, p) = -ylogp-(1-y)log(1-p)$
    - $y \in$  {0, 1} 일 때, focal loss가 제안된 soft-target focal loss의 special case인지 확인할 수 있음

### 3.2. Anchor-level Target Prediction

- detection model이 보다 구조화된 클래스 레이블과 반대로 target object에 대한 bounding box를 출력하기 때문에 기존 target prediction 방법을 classfication에서 detection으로 이전하는 것은 사소한 문제가 아님

    → FocalMix 에서는 앵커 수준에서 이 문제에 접근할 것을 제안함

- training 중 원본 이미지에서 동일한 크기 (160x160x160)의 patch를 샘플링 함
- 이미지 patch의 길이가 FPN에 사용된 최대 stride(e.g., 16)으로 나누어 지도록 함
- 이미지 patch의 각 anchor는 회전하거나 뒤집은 후에 항상 다른 anchor의 위치로 떨어질 수 있음
- 그 다음 모델을 사용하여 변환된 이미지 patch에서 객체와 일치하는 각 anchor의 확률을 예측
- 그 다음 역변환하여 원래 patch의 각 anchor에 대해 추측된 target을 얻을 수 있음
- data augmentation을 K번 반복하고 patch의 각 anchor에 대해 K개의 추측 target을 생성
- 추측 target을 평균 앙상블 별로 집계 후 주어진 patch에 대한 낮은 엔트로피 예측 target을 얻기 위해 anchor-wise sharpening 연산

### 3.3. MixUp Augmentation for Detection

- MixUp Augmentation은 더 나은 일반화 성능을 위해 모델이 training example 사이에 선형으로 포함되도록 함
- **vanilla MixUp**은 사용할 수 없음
- **Image-level MixUp**
    - 두 이미지를 mix할 때 training target을 mix하는 방법이 어려움
    - 의료 영상에서 detection task를 위한 실제 레이블은 bounding box이지만, 두 bounding box set에 interpolation을 취함으로써 classfication에서 soft class와 같은 의미있는 것을 얻을 수 없음
    - 그래서 anchor level에서 training signal을 mix하는 것을 제안
    - 각 anchor에 대한 training target과 함께 동일한 크기의 두 개의 이미지가 제공되면 augmented sample 생성

    ![4C1ADB8B-2F1D-40A1-9FF1-C3DB4048471B](https://user-images.githubusercontent.com/51358226/96604284-e61d4280-132f-11eb-97e5-169cd2dc72b7.jpeg)


    - Image-level MixUp은 병변 탐지 작업에서 보다 직관적인 해석을 제공하며, 목표는 background texture와 병변을 구별하는 것
    - anchor-to-anchor mixup에서는 모델이 altitude training 아이디어와 유사하게 일반적인 background noise와 강한 background noise가 혼합된 병변을 감지할 수 있어야 함
- Object-level MixUp
    - 의료 영상에서 병변의 수는 실제로 많지 않음
    - 각 training batch 내에서 서로 다른 병변 패턴을 혼합하여 추가 객체 인스턴스를 생성할 것을 제안함
        - training batch의 각 이미지 내 각 객체에 대해 현재 batch에서 다른 객체를 무작위로 샘플링하고 동일한 크기로 다시 스케일링 한 다음 두 객체를 위의 식과 같은 방식으로 mix함
    - label이 없는 object의 경우 prediction confidence가 높은 predicted box는 탐지된 object로 취급
    - 이러한 모든 object는 positive example일 확률이 높으므로 simple함을 위해 training target을 더이상 mix하지 않음

## 4. Experiments

### 4.1. Experimental setup

- **Detection Model**
- **Semi-supervised Learning**
    - 동일한 개수의(8개) 레이블이 지정된 데이터와 레이블이 없는 데이터를 batch로 사용
    - 레이블이 없는 데이터에 soft target focal loss 적용
    - MixUp augmentation의 경우 이미지 수준 MixUp이 먼저 적용된 다음 object 수준 MixUp
- **Fully-Supervised Baseline Performance**
    - "Realistic evaluation of deep semi-supervised learning algorithm" 에서와 같이 평가를 위해 잘 조정된 강력하게 supervised 된 baseline과 비교하고 이를 토대로 구축해야 함
