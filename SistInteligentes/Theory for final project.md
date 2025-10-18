## Machine Learning with PyTorch and Scikit-learn

### 11. Implementing a Multilayer Artificial Neural Network

Topics covered:
- Conceptual understanding of multilayer NNs;
- Implementing the fundamental backpropagation algorithm for NN training from scratch, and
- Training a basic multilayer NN for image classification

#### Modeling complex functions with artificial neural networks

McCulloh-Pitts neuron model --> Rosenblatt's perceptron --> Everyone lost interest because no one had a good solution for training a NN with multiple layers, until...

Rumelhart, Hinton, and Williams were involved in the (re)discovery and popularization of the backpropagation algorithm to train NNs more efficiently (1986).

*Note*: check out this [link](https://en.wikipedia.org/wiki/AI_winter) for more history, and read the papers from these researchers (*A logical calculus of the ideas immanenet in nervous activity*, and *Learning representations by backpropagating errors*).

##### Single-Layer neural network recap

###### Artificial neuron

We can define a decision function $\sigma (z)$ that takes a linear combination of certain input values $\mathbf{x}$, and a corresponding weight vector $\mathbf{w}$, where the net input is $z = w_1x_1 + w_2x_2 + ... + w_mx_m$. If the net input of a particular example is greater than a defined threshold $\theta$, we predict class 1, and class 0 otherwise (for binary classification).
In the perceptron algorithm, the decision function is a variant of a *unit step function*:
$$
\sigma(z) = \begin{cases}
1 & \text{if } z \geq \theta\\
0  & \text{otherwise}\\
\end{cases}
$$
To simplify the implementation, we can modify the setup as
$$
\begin{align*}
z \geq \theta \\
z - \theta \geq 0
\end{align*}
$$
So now we can define the bias $b = - \theta$, and make it part of the net input:
$$
z = \mathbf{w}^T \mathbf{x} + b = w_1x_1 + w_2x_2 + ... + w_mx_m + b
$$
Now the decision (activation) function can be defined as
$$
\sigma(z) = \begin{cases}
1 & \text{if } z \geq 0\\
0  & \text{otherwise}\\
\end{cases}
$$

###### Perceptron Learning Rule

MCP neuron & Rosenblatt's thresholded perceptron model tries to mimic how a single neuron in the brain works: it **fires** or it doesn't. Thus, Rosenblatt's classic perceptron rule is simple:
1. Initialize weights and bias to 0
2. For each training example:
	1. Compute its output value
	2. Update the weights and bias unit

The output value is the class label predicted by the *unit step function* defined earlier, and the updates can be formally written as:
$$
\begin{align*}
w_j &:= w_j + \Delta w_j \\
b &:= b + \Delta b
\end{align*}
$$
The update values (deltas) are computed as follows:
$$
\begin{align*}
\Delta w &:= \eta(y^{(i)} - \hat{y}^{(i)})x_{j}^{(i)} \\
\Delta b &:= \eta(y^{(i)} - \hat{y}^{(i)})
\end{align*}
$$

Note that each weight $w_j$ corresponds to a feature $x_j$ in the dataset and is involved in determining the update value $\Delta w_j$, while the bias unit does not. Also, $\eta$ is the **learning rate** (usually between 0 and 1), $y^{(i)}$ is the **true class label** of the $i$-th training example, and $\hat{y}^{(i)}$ is the **predicted class label**.

The beauty of this algorithm is in its simplicity: if the perceptron predicts the label correctly, the bias and weights remain unchanged (update values are 0); in case of a wrong prediction, the weights are pushed toward the direction of the positive or negative target class ($\pm \eta$).

Why is the weight update multiplied by the feature value?
...