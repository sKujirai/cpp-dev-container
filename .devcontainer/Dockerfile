# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.134.0/containers/cpp/.devcontainer/base.Dockerfile
ARG VARIANT="buster"
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}

# Environmental variables
ARG REMOTE_USER="vscode"
ARG WORK_DIR="/work"
ARG EIGEN_VERSION=3.3.8
ARG XTL_VERSION=0.6.21
ARG XTENSOR_VERSION=0.21.8
ARG XBLAS_VERSION=0.17.2
ARG SPDLOG_VERSION=v1.8.1
ARG BOOST_VERSION=1.70.0
ARG VTKMESH_VERSION=v1.0.0
ARG TMP_WORK_DIR="/tmp_work"

# Avoid warnings by switching to noninteractive
ENV DEBIAN_FRONTEND=noninteractive

# Configure apt and install packages
RUN apt-get update \
    && apt-get -y install ncftp libopenblas-dev liblapack-dev

# Clean up
RUN apt-get autoremove -y \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/*

# Install library
RUN mkdir ${TMP_WORK_DIR}

# Eigen
RUN cd ${TMP_WORK_DIR} \
    && git clone https://gitlab.com/libeigen/eigen.git \
    && cd ${TMP_WORK_DIR}/eigen \
    && git checkout ${EIGEN_VERSION} \
    && cd ${TMP_WORK_DIR} \
    && mv ${TMP_WORK_DIR}/eigen /opt/ \
    && ln -s /opt/eigen/Eigen/ /usr/local/include/Eigen \
    && ln -s /opt/eigen/unsupported/ /usr/local/include/unsupported

# xtl
RUN cd ${TMP_WORK_DIR} \
    && git clone https://github.com/xtensor-stack/xtl.git \
    && cd ${TMP_WORK_DIR}/xtl \
    && git checkout ${XTL_VERSION} \
    && mkdir ${TMP_WORK_DIR}/xtl/build \
    && cd ${TMP_WORK_DIR}/xtl/build \
    && cmake -DCMAKE_INSTALL_PREFIX=/usr/local .. \
    && make install \
    && cd ${TMP_WORK_DIR}

# xtensor
RUN cd ${TMP_WORK_DIR} \
    && git clone https://github.com/xtensor-stack/xtensor.git \
    && cd ${TMP_WORK_DIR}/xtensor \
    && git checkout ${XTENSOR_VERSION} \
    && mkdir ${TMP_WORK_DIR}/xtensor/build \
    && cd ${TMP_WORK_DIR}/xtensor/build \
    && cmake -DCMAKE_INSTALL_PREFIX=/usr/local .. \
    && make install \
    && cd ${TMP_WORK_DIR}

# xtensor-blas
RUN cd ${TMP_WORK_DIR} \
    && git clone https://github.com/xtensor-stack/xtensor-blas.git \
    && cd ${TMP_WORK_DIR}/xtensor-blas \
    && git checkout ${XBLAS_VERSION} \
    && mkdir ${TMP_WORK_DIR}/xtensor-blas/build \
    && cd ${TMP_WORK_DIR}/xtensor-blas/build \
    && cmake -DCMAKE_INSTALL_PREFIX=/usr/local .. \
    && make install \
    && cd ${TMP_WORK_DIR}

# spdlog
RUN cd ${TMP_WORK_DIR} \
    && git clone https://github.com/gabime/spdlog.git \
    && cd ${TMP_WORK_DIR}/spdlog \
    && git checkout ${SPDLOG_VERSION} \
    && cd ${TMP_WORK_DIR} \
    && mv ${TMP_WORK_DIR}/spdlog /opt/ \
    && ln -s /opt/spdlog/include/spdlog/ /usr/local/include/spdlog

# Boost
RUN cd ${TMP_WORK_DIR} \
    && git clone https://github.com/boostorg/boost.git \
    && cd ${TMP_WORK_DIR}/boost \
    && git checkout ${BOOST_VERSION} \
    && git submodule update --init --recursive \
    && ./bootstrap.sh \
    && ./b2 install -j2 --prefix=/usr/local; exit 0

# vtkmesh
RUN cd ${TMP_WORK_DIR} \
    && git clone https://github.com/sKujirai/vtkmesh.git \
    && cd ${TMP_WORK_DIR}/vtkmesh \
    && git checkout ${VTKMESH_VERSION} \
    && mkdir /opt/vtkmesh \
    && mv ${TMP_WORK_DIR}/vtkmesh /opt/vtkmesh/

RUN rm -rf ${TMP_WORK_DIR}

# chown all files to remote user
RUN mkdir ${WORK_DIR} \
    && chown -R ${REMOTE_USER} ${WORK_DIR}
